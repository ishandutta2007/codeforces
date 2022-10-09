uses math;
var
    ntest: longint;
    a, b: int64;
    d, dx, dy: int64;
begin
    read(ntest);
    while ntest > 0 do begin
        dec(ntest);
        read(a, b);
        d := 1 - 4;
        dx := a - 2 * b;
        dy := b - 2 * a;
        if (dx mod d <> 0) or (dy mod d <> 0) or (dx div d < 0) or (dy div d < 0) then
            writeln('NO')
        else
            writeln('YES');
    end;
end.