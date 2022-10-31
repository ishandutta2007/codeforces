var
  ans,n:longint;
  i,x:longint;
  a:Array[1..100000]of longint;
begin
  fillchar(a,sizeof(a),0);
  read(n);
  for i:=1 to n do
  begin
    read(x);
    inc(a[x]);
  end;
  ans:=0;
  for i:=1 to 100000 do
    if a[i]>1 then
    begin
      ans:=ans+a[i]-1;
      a[i+1]:=a[i+1]+a[i]-1;
      a[i]:=1;
    end;
  writeln(ans);
end.