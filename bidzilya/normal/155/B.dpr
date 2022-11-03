program task_2;
{$apptype console r+ q+}
uses Math,SysUtils;
const nmax = 1000;
var
     n,i,j,tb,ta: integer;
     a,b: array[1..nmax]of integer;

procedure qsort(l,r: integer);
var i,j,x,buf: integer;
begin
  i:=l;j:=r;x:=a[i+random(j-i+1)];
  repeat
    while (a[i]<x)do inc(i);
    while (a[j]>x)do dec(j);
    if (i<=j)then begin
      buf:=a[i];a[i]:=a[j];a[j]:=buf;
      buf:=b[i];b[i]:=b[j];b[j]:=buf;
      inc(i);dec(j);
    end;
  until (i>j);
  if (i<r)then qsort(i,r);
  if (j>l)then qsort(l,j);
end;

begin
randomize;
  read(n);
  ta:=0;
  tb:=1;
  for i:=1 to n do read(a[i],b[i]);
  qsort(1,n);
  for i:=1 to n do
    if (b[i]>0)then begin
      tb:=tb+b[i]-1;
      ta:=ta+a[i];
    end;
  for i:=n downto 1 do
    if (tb<>0)and(b[i]=0)then begin
      dec(tb);
      ta:=ta+a[i];
    end;
  write(ta);
end.