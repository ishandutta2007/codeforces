var d:array[1..100]of longint;
    i,j,n,l,p,ko,ma:longint;
begin
readln(n,l);ma:=0;
for i:=1 to n do begin
    read(d[i]);
    if d[i]>ma then ma:=d[i];
    end;
ko:=0;
for i:=l to ma do begin
    p:=0;
    for j:=1 to n do p:=p+(d[j]div i);
    if p*i>ko then ko:=p*i;
    end;
if ko<l then writeln(0)
        else writeln(ko);
end.