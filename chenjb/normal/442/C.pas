var
  a:Array[1..800000]of int64;
  n,i,x,top:longint;
  ans:int64;
function min(x,y:int64):int64;
begin
  if x<y then exit(x) else exit(y);
end;
procedure qsort(left,right:longint);
var
  mid,t:int64;
  i,j:longint;
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
begin
 
  read(n);
  top:=0;
  ans:=0;
  for i:=1 to n do
  begin
    inc(top);
    read(a[top]);
    while (top>=3)and(a[top-2]>=a[top-1])and(a[top-1]<=a[top])do
    begin
      ans:=ans+min(a[top-2],a[top]);
      a[top-1]:=a[top];
      dec(top);
    end;
  end;
  qsort(1,top);
  for i:=1 to top-2 do ans:=ans+a[i];
  writeln(ans);

end.