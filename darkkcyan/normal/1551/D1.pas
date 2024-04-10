uses math;

const need_reconstruct = false;

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

procedure do_reconstruct;
begin
    if not need_reconstruct then exit();
end;

begin
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