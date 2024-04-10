var t,k,n,i,y,j,r:longint;
m:array [0..9] of longint;

begin
read(n,k);
y:=0;
for i:=1 to n do
begin
read(t);
for j:=0 to k do
m[j]:=0;
while t>0 do
begin
m[t mod 10]:=1;
t:=t div 10;
end;
r:=0;
for j:=0 to k do
r:=r+m[j];
if r=k+1 then y:=y+1;
end;
writeln(y);
end.