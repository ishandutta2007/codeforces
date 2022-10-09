uses math;

const need_reconstruction = true;  // change to false for D1
const maxn = 111;

var ntest: longint;
var n, m, k: longint;
var min_hor: longint;
var max_hor: longint;
var rest: longint;

function check_sol: boolean;
begin
    if n mod 2 = 1 then begin
        min_hor := m div 2;
    end else begin
        min_hor := 0;
    end;
    
    if m mod 2 = 1 then begin
        max_hor := n * m div 2 - n div 2;
    end else begin
        max_hor := n * m div 2;
    end;
    if (k < min_hor) or (k > max_hor) then exit(false);
    rest := k - min_hor;
    if rest mod 2 = 1 then exit(false);
    exit(true);
end;

var board: array[0..maxn, 0..maxn] of byte;  // change to char later
procedure do_reconstruct;
const ab = ord('a') xor ord('b');
const cd = ord('c') xor ord('d');
var
    i, f, r, c: longint;
    cur_ch: byte;
    
begin
    // if not need_reconstruction then exit(); 
    for i := 1 to n do for f := 1 to m do board[i][f] := 0;
    
    cur_ch := ord('a');
    for i := 1 to min_hor do begin
        board[1][2 * i - 1] := cur_ch;
        board[1][2 * i] := cur_ch;
        cur_ch := cur_ch xor ab;
    end;
    
    cur_ch := ord('c');
    for i := 1 to n * m div 2 - max_hor do begin
        board[2 * i - 1][m] := cur_ch;
        board[2 * i][m] := cur_ch;
        cur_ch := cur_ch xor cd;
    end;
    
    if min_hor > 0 then r := 2
    else r := 1;
    c := 1;
    for i := 1 to rest div 2 do begin
        if c + 1 > m then begin
            inc(r, 2);
            c := 1;
        end;
        if r = 1 then begin
            if c = 1 then cur_ch := ord('a')
            else cur_ch := board[r][c - 1] xor ab;
        end else cur_ch := board[r - 1][c] xor ab;
        
        board[r][c] := cur_ch;
        board[r][c + 1] := cur_ch;
        board[r + 1][c] := cur_ch xor ab;
        board[r + 1][c + 1] := cur_ch xor ab;
        inc(c, 2);
    end;
    
    r := 1;
    if min_hor > 0 then inc(r);
    for i := 1 to n do begin
        for f := m downto 1 do begin
            if board[i][f] <> 0 then continue;
            if f = m then begin
                if (i = 1) or ((board[i - 1][f] <> ord('c')) and (board[i - 1][f] <> ord('d'))) then cur_ch := ord('c')
                else cur_ch := board[i - 1][f] xor cd
            end else cur_ch := board[i][f + 1] xor cd;
            board[i][f] := cur_ch;
            board[i + 1][f] := cur_ch;
        end;
    end;
    
    for i := 1 to n do begin
        for f := 1 to m do write(chr(board[i][f]));
        writeln;
    end;
end;

procedure check;
var i: longint;
var f: longint;
begin
    for i := 1 to 5 do begin
        for f := 1 to 5 do begin
            if i * f mod 2 = 1 then continue;
            for k := 0 to i * f div 2 do begin
                writeln(i, ' ', f, ' ', k);
                n := i;
                m := f;
                if not check_sol then begin
                    writeln('NO');
                    continue;
                end;
                writeln('YES');
                do_reconstruct;
                
            end;
        end;
    end;
end;

begin
    // check(); 
    // writeln; 
    //  
    read(ntest);
    while ntest > 0 do begin
        dec(ntest);
        read(n, m, k);
        
        if not check_sol then begin
            writeln('NO');
            continue;
        end;
        writeln('YES');
        do_reconstruct;
    end;
    
end.