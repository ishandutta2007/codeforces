program task_D;

{$APPTYPE CONSOLE}
const nmax = 2000;
      md = 1087;
var t,s1,s2: string;
    hash: array[0..nmax,0..nmax]of int64;
    q: array[0..nmax*nmax]of int64;
    h1,h2: int64;
    i,j,len,left,right: integer;
procedure qsort(l,r: integer);
var buf,x: int64;
    i,j: integer;
begin
  i:=l;j:=r;x:=q[i+random(j-i+1)];
  repeat
    while (q[i]<x)do inc(i);
    while (q[j]>x)do dec(j);
    if (i<=j)then begin
      buf:=q[i];q[i]:=q[j];q[j]:=buf;
      inc(i);dec(j);
    end;
  until (i>j);
  if (i<r)then qsort(i,r);
  if (j>l)then qsort(l,j);
end;
begin
randomize;
  readln(t);
  readln(s1);
  readln(s2);
  for i:=1 to length(t)do hash[i,i-1]:=0;
  for i:=1 to length(t)do
    for j:=1 to length(t)-i+1 do
      hash[j,i+j-1]:=hash[j,i+j-2]*md+ord(t[i+j-1]);
  h1:=0;
  for i:=1 to length(s1)do h1:=h1*md+ord(s1[i]);
  h2:=0;
  for i:=1 to length(s2)do h2:=h2*md+ord(s2[i]);
  len:=0;
  for i:=1 to length(t)do
    for j:=1 to length(t)-i+1 do begin
      left:=j;
      right:=j+i-1;
      if (left+length(s1)-1<=right)and(right-length(s2)+1>=left)and
         (hash[left,left+length(s1)-1]=h1)and
         (hash[right-length(s2)+1,right]=h2)then begin
          inc(len);
          q[len]:=hash[left,right];
         end;
    end;
  if (len = 0)then begin
    writeln(0);
    halt;
  end;
  qsort(1,len);
  i:=1;
  for j:=2 to len do
    if (q[j]<>q[j-1])then inc(i);
  write(i);
end.