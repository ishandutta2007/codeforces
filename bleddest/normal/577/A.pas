program za;
var n, x, e, f, i: longint;
begin
readln (n, x);
e:=0;
f:=round(sqrt(x));
i:=1;
while (i<=n) and (i<=f) do begin
        if (x mod i = 0) and (x div i <= n) then e:=e+2;
        if (x = sqr(i)) then e:=e-1;
        i:=i+1;
end;
writeln (e);
end.