var n,c,i,j,k,ko:longint;
    x:array[1..100]of longint;
begin
readln(n,c);
for i:=1 to n do read(x[i]);
ko:=0;
for i:=1 to n-1 do begin
    k:=x[i]-x[i+1]-c;
    if k>ko then ko:=k;
    end;
writeln(ko);
end.