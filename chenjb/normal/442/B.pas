var
  a:array[1..200]of extended;
  f:array[0..200,0..1]of extended;
  i,n:longint;
  ans:extended;
procedure qsort(left,right:longint);
var
  i,j:longint;
  t,mid:extended;
begin
  if left>=right then exit;
  i:=left;
  j:=right;
  mid:=a[(i+j)div 2];
  repeat
    while a[i]>mid do inc(i);
    while a[j]<mid do dec(j);
    if i<=j then
    begin
      t:=a[i];
      a[i]:=a[j];
      a[j]:=t;
      inc(i);
      dec(j);
    end;
  until i>j;
  qsort(left,j);
  qsort(i,right);
end;
begin

  read(n);
  for i:=1 to n do read(a[i]);
  qsort(1,n);
  fillchar(f,sizeof(f),0);
  f[0,0]:=1;
  for i:=1 to n do
  begin
    f[i,0]:=f[i-1,0]*(1-a[i]);
    f[i,1]:=f[i-1,0]*a[i]+f[i-1,1]*(1-a[i]);
  end;
  ans:=0;
  for i:=1 to n do
    if ans<f[i,1] then ans:=f[i,1];
  writeln(ans:0:10);

end.