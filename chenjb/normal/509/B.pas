var
  t,i,j,n,m:longint;
  a:array[1..200]of longint;
  max,min:longint;
begin

  readln(n,m);
  max:=-2147483647;
  min:=2147483647;
  for i:=1 to n do
  begin
    read(a[i]);
    if a[i]>max then max:=a[i];
    if a[i]<min then min:=a[i];
  end;
  if max-min>m then writeln('NO')
  else
  begin
    writeln('YES');
    for i:=1 to n do
    begin
      t:=1;
      for j:=1 to a[i] do
      begin
        if j<>1 then write(' ');
        write(t);
        inc(t);
        if t>m then t:=1;
      end;
      writeln;
    end;
  end;

end.