program task_4;

{$APPTYPE CONSOLE}
const nmax = round(1e5);
var a,cnt: array[1..nmax]of integer;
    n,i,j,len: integer;
procedure qsort(l,r: integer);
var i,j,x,buf: integer;
begin
  i:=l;j:=r;x:=a[i+random(j-i+1)];
  repeat
    while (a[i]<x)do inc(i);
    while (a[j]>x)do dec(j);
    if (i<=j)then begin
      buf:=a[i];a[i]:=a[j];a[j]:=buf;
      inc(i);dec(j);
    end;
  until (i>j);
  if (i<r)then qsort(i,r);
  if (j>l)then qsort(l,j);
end;
begin
//assign(input,'input.txt');reset(input);
//assign(output,'output.txt');rewrite(output);
randomize;
  read(n);
  for i:=1 to n do read(a[i]);
  qsort(1,n);
  len:=1;
  cnt[1]:=1;
  for i:=2 to n do
    if (a[i]<>a[len])then begin
      inc(len);
      a[len]:=a[i];
      cnt[len]:=1;
    end else inc(cnt[len]);
  for i:=2 to len do
    if (a[i]<>a[i-1]+1)then begin
      writeln('NO');
      halt;
    end;
  for i:=2 to len do begin
    cnt[i]:=cnt[i]-cnt[i-1];
    if (cnt[i]<0)or((cnt[i]=0)and(i<>len))then begin
      writeln('NO');
      halt;
    end;
  end;
  if (cnt[len]<>0)then writeln('NO')
    else writeln('YES');
end.