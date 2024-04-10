var a,b:array[1..100000]of int64;
    n,i,j,k,d,x:longint;ko:int64;
begin
readln(n,x);
fillchar(b,sizeof(b),0);
for i:=1 to n do begin
    read(k);b[k]:=b[k]+1;
    end;
j:=0;
for i:=1 to 100000 do
    if b[i]>0 then
       for d:=1 to b[i] do begin
           inc(j);
           a[j]:=i;end;
ko:=0;
for i:=1 to n do begin
    ko:=ko+a[i]*x;
    if x>1 then x:=x-1;
    end;
writeln(ko);
end.