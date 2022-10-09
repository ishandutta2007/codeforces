uses math;

var 
    ntest: longint;
    x, n: longint;

begin
    read(ntest);
    while ntest > 0 do begin
        dec(ntest);
        read(n, x);
        writeln(2 * x);
    end;
end.