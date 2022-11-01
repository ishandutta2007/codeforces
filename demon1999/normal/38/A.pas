var d:array[1..100]of longint;
    i,j,a,b,n:longint;
begin
readln(input,n);
for i:=1 to n-1 do read(d[i]);
readln(a,b);
n:=0;
for i:=a to b-1 do n:=n+d[i];
writeln(n);
end.