var x,c:array[1..3010]of int64;
    a:array[1..2,1..3010]of int64;
    n,i,j:longint;
    p,k:int64;
procedure sort(l,r:longint);
var i,j:longint;tm,tm1:int64;
begin
tm:=x[(l+r)div 2];
i:=l;j:=r;
while i<j do begin
      while x[i]<tm do inc(i);
      while x[j]>tm do dec(j);
      if i<=j then begin
         tm1:=x[i]; x[i]:=x[j]; x[j]:=tm1;
         tm1:=c[i]; c[i]:=c[j]; c[j]:=tm1;
         inc(i);dec(j);
         end;
end;
if i<r then sort(i,r);
if j>l then sort(l,j);
end;
begin
readln(n);
for i:=1 to n do
    readln(x[i],c[i]);
if n=1 then begin writeln(c[1]);halt;end;
sort(1,n);
a[1,1]:=c[1];
a[1,2]:=a[1,1]+c[2];
a[2,2]:=a[1,1]+x[2]-x[1];
for i:=3 to n do begin
    a[1,i]:=c[i];
    if a[1,i-1]>a[2,i-1] then inc(a[1,i],a[2,i-1])
                         else inc(a[1,i],a[1,i-1]);
    k:=x[i]-x[i-1];
    a[2,i]:=a[1,i-1]+k;
    p:=2;
    for j:=i-2 downto 1 do begin
        k:=k+p*(x[j+1]-x[j]);
        if a[1,j]+k<a[2,i] then a[2,i]:=a[1,j]+k;
        inc(p);
        end;
end;
if a[2,n]>a[1,n] then write(a[1,n])
                 else write(a[2,n]);
end.