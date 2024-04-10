type
  node=record
    x,y:int64;
  end;
var
  a:array[1..500001]of node;
  i,n,ans:longint;
  now:int64;
procedure qsort(left,right:longint);
var
  i,j:longint;
  mid:longint;
  t:node;
begin
  if left>=right then exit;
  i:=left;
  j:=right;
  mid:=a[(i+j)div 2].x;
  repeat
    while a[i].x<mid do inc(i);
    while a[j].x>mid do dec(j);
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

  readln(n);
  for i:=1 to n do readln(a[i].x,a[i].y);
  qsort(1,n);
  now:=-21474836470000000;
  ans:=0;
  for i:=1 to n do
  begin
    if a[i].x-a[i].y>now then
    begin
      now:=a[i].x;
      inc(ans);
    end
    else if (i=n)or(a[i].x+a[i].y<a[i+1].x)then
    begin
      now:=a[i].x+a[i].y;
      inc(ans);
    end
    else now:=a[i].x;
  end;
  writeln(ans);

end.