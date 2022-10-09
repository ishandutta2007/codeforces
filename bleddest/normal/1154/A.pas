var x1, x2, x3, x4, max: longint;

begin
    readln(x1, x2, x3, x4);
    max := x1;
    if max < x2 then max := x2;
    if max < x3 then max := x3;
    if max < x4 then max := x4;
    if max <> x1 then writeln(max - x1);
    if max <> x2 then writeln(max - x2);
    if max <> x3 then writeln(max - x3);
    if max <> x4 then writeln(max - x4);
end.