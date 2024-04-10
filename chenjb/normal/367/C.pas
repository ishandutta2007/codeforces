var
  a:array[1..100001]of longint;
  n,m:longint;
  x,y,i,j:longint;
  t,sum:longint;
procedure qsort(left,right:longint);
var
  i,j,t,mid:longint;
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

  read(n,m);
  for i:=1 to m do read(x,a[i]);
  qsort(1,m);
  sum:=0;
  for i:=1 to m do
  begin
    if i mod 2=0 then
    begin
      t:=(i-1)div 2*i+i;
      if t<=n then sum:=sum+a[i]
      else break;
    end
    else
    begin
      t:=(i-1)div 2*i+1;
      if t<=n then sum:=sum+a[i]
      else break;
    end;
  end;
  writeln(sum);

end.