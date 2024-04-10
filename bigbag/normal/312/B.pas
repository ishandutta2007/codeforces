var a, b, c, d : longint;
    x, y, v1, v2, k, m : real;
begin
read(a, b, c, d);
x := a / b;
y := c / d;
v1 := x;
k := 1 - v1;
v2 := k * y;
k := k - v2;
m := 0;
while v1 - m >= 0.000000001 do
begin
  m := v1;
  v1 := v1 + k * x;
  k := k - k * x;
  v2 := v2 + k * y;
  k := k - k * y;
end;
write(v1 : 0 : 7);

end.