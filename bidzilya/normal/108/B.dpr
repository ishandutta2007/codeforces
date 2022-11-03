var
  i,n:integer;
  a:array[1..100000]of integer;
  
procedure fastsort(l,r:integer);
var i,tmp,j,x:integer;
begin
  i:=l;
  j:=r;
  x:=a[(i+j)shr 1];
  repeat
    while a[i]>x do inc(i);
    while a[j]<x do dec(j);
    if i<=j then begin
      tmp:=a[i];
      a[i]:=a[j];
      a[j]:=tmp;
      inc(i);
      dec(j);
    end;
  until i>j;
  if i<r then fastsort(i,r);
  if j>l then fastsort(l,j);
end;
  
begin
  //assign(input,'input.txt');reset(input);
  read(n);
  for i:=1 to n do 
    read(a[i]);
  fastsort(1,n);
  for i:=2 to n do
    if (a[i-1]<>a[i])and(a[i-1]<a[i]*2) then begin
      write('YES');
      halt;
    end;
  write('NO');
end.