var
  n:longint;
  a:array[1..200001]of int64;
  i,ans:longint;
  now:int64;
procedure qsort(left,right:longint);
var
  i,j:longint;
  t,mid:int64;
begin
  if left>=right then exit;
  i:=left;
  j:=right;
  mid:=a[left+random(right-left+1)];
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
begin
  randomize;
  
  read(n);
  for i:=1 to n do read(a[i]);
  qsort(1,n);
  now:=0;
  ans:=0;
  for i:=1 to n do
    if now<=a[i] then
    begin
      now:=now+a[i];
      inc(ans);
      if now>a[n] then break;
    end;
  writeln(ans);

end.