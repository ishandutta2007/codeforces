var
  a:array[0..200000]of longint;
  i,j,k,t,n:longint;
procedure p(l,r:longint);
begin
   i:=l;j:=r;
   k:=a[(i+random(j-i))];
 repeat
   while a[i]<k do inc(i);
   while k<a[j] do dec(j);
   if i<=j then begin
     t:=a[i];a[i]:=a[j];a[j]:=t;
     inc(i);dec(j);
   end;
 until i>j;
 if i<r then p(i,r);
 if l<j then p(l,j);
end;

begin
  randomize;
  readln(n);
  for i:=1 to n do read(a[i]);
  k:=1;
  for i:=2 to n do if a[i]>a[k]then k:=i;
  if a[k]=1 then
    a[k]:=2
  else
    a[k]:=1;
  p(1,n);
  for i:=1 to n do write(a[i],' ');
end.