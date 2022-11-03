program task_5;

{$apptype console}
const h = 1000007;
      nmax = 1000000;
var ans,cnt: int64;
    st: array[0..nmax]of int64;
    v1,v2: array[1..nmax]of integer;
    n,m,i,j: integer;
    a: array[1..nmax]of int64;

procedure qsort(l,r: integer);
var i,j: integer;
    x,buf: int64;
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
  read(n,m);
  st[0]:=1;
  for i:=1 to n do st[i]:=st[i-1]*h;
  for i:=1 to n do a[i]:=st[i];
  for i:=1 to m do begin
    read(v1[i],v2[i]);
    a[v1[i]]:=a[v1[i]]+st[v2[i]];
    a[v2[i]]:=a[v2[i]]+st[v1[i]];
  end;
  qsort(1,n);
  i:=1; ans:=0; cnt:=1;
  for j:=2 to n do
    if (a[j]<>a[i])then begin
      ans:=ans+cnt*(cnt-1)div 2;
      cnt:=1;
      inc(i);
      a[i]:=a[j];
    end else inc(cnt);
  ans:=ans+cnt*(cnt-1)div 2;
  for i:=1 to n do a[i]:=0;
  for i:=1 to m do begin
    a[v1[i]]:=a[v1[i]]+st[v2[i]];
    a[v2[i]]:=a[v2[i]]+st[v1[i]];
  end;
  qsort(1,n);
  i:=1;cnt:=1;
  for j:=2 to n do
    if (a[j]<>a[i])then begin
      ans:=ans+cnt*(cnt-1)div 2;
      cnt:=1;
      inc(i);
      a[i]:=a[j];
    end else inc(cnt);
  ans:=ans+cnt*(cnt-1)div 2;
  write(ans);
end.