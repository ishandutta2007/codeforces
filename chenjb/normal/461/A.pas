var
  n:longint;
  a:array[1..301001]of longint;
  sum:int64;
  ans:int64;
procedure qsort(left,right:longint);
var
  i,j:longint;
  t,mid:longint;
begin
  if left>=right then exit;
  i:=left;
  j:=right;
  mid:=a[(i+j)div 2];
  repeat
    while a[i]<mid do inc(i);
    while a[j]>mid do dec(j);
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
var
  i:longint;
begin

  read(n);
  sum:=0;
  for i:=1 to n do
  begin
    read(a[i]);
    sum:=sum+a[i];
  end;
  qsort(1,n);
  ans:=sum;
  for i:=1 to n-1 do
  begin
    ans:=ans+sum;
    sum:=sum-a[i];
  end;
  writeln(ans);

end.