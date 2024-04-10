uses math;

var ntest: longint;
var n, x: int64;

begin
    read(ntest);
    while ntest > 0 do begin
        dec(ntest);
        read(n);
        x := n div 3;
        if n mod 3 = 0 then writeln(x, ' ', x)
        else if n mod 3 = 1 then writeln(x + 1, ' ', x)
        else writeln(x, ' ', x + 1);
    end;
end.