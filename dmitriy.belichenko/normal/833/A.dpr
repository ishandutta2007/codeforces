var  k ,x, t :int64;
a, b :integer;
r  , d: longint;
n , i: integer;
begin
read(n);

for i:=1 to n do
begin
read(a);
readln(b);
k:=0;
if (a=1) and (b=1) then writeln('Yes')
else
begin
x:=a*b;
r:=round(exp ((ln (a) + ln(b)) / 3));
d:= r ;
t:=d*d*d;
while (t<x) do 
begin
 d:=d+1;
 t := d * d * d;
end;
 
while (t>x) do
 begin
 d:=d - 1;
 t := d * d * d;
end;
if (t=x) then k:=k+1;

if (a mod d=0) and (b mod d=0)then k:=k+1;


if k=2 then writeln('Yes')
else writeln('No');
end;
end;
end.