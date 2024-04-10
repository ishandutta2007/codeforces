uses math;

const maxn = 11;

type board_t = array[0..maxn] of string;

var
    ntest: longint;
    n, m, k: longint;
    board: board_t;
    
procedure do_fill(var b: board_t; r, c, sz: longint);
var
    i, f, g: longint;
begin
    i := r;
    f := c;
    g := c;
    while sz > 0 do begin
        b[i][f] := '*';
        b[i][g] := '*';
        dec(i);
        dec(f);
        inc(g);
        dec(sz);
    end;
end;

function fill_size(r, c: longint): longint;
var
    i, f, g: longint;
    filled: longint;
begin
    i := r;
    f := c;
    g := c;
    filled := 0;
    while (i > 0) and (f > 0) and (g <= m) and (board[i][f] = '*') and (board[i][g] = '*') do begin
        dec(i);
        dec(f);
        inc(g);
        inc(filled);
    end;
    exit(filled);
end;

var
    i, f, fs: longint;
    my_board: board_t;
    ok: boolean;

begin
    readln(ntest);
    while ntest > 0 do begin
        dec(ntest);
        readln(n, m, k);
        for i := 1 to n do readln(board[i]);
        
        for i := 1 to n do begin
            my_board[i] := '';
            for f := 1 to m do my_board[i] := my_board[i] + '.';
        end;
        
        for i := 1 to n do begin
            for f := 1 to m do begin
                fs := fill_size(i, f);
                if fs <= k then continue;
                do_fill(my_board, i, f, fs);
            end;
        end;
        ok := true;
        for i := 1 to n do begin
            for f := 1 to m do begin
                if board[i][f] = my_board[i][f] then continue;
                ok := false;
                break;
            end;
            if not ok then break;
        end;
        if ok then writeln('YES')
        else writeln('NO');
    end;
end.