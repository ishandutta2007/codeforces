program A3;
var n, i, a, b, c, z:integer;
    d, e:array[1..100] of integer;
begin
  readln(n);
  for i:=1 to n do
  begin
    read(d[i]);
    e[i]:=0;
    if d[i]=0 then c:=c+1;
    if d[i]<0 then a:=a+1;
  end;
  if a mod 2 = 0 then
  begin
    c:=c+1;
    a:=1;
    b:=n-a-c;
    z:=0;
    for i:=1 to n do
    begin
      if d[i]>0 then e[i]:=2
      else if d[i] = 0 then e[i]:=3
      else
      begin
        if z = 0 then
        begin
          e[i]:=1;
          z:=1;
        end
        else if z=1 then
        begin
          z:=2;
          e[i]:=3;
        end
        else e[i]:=2;
      end;
    end;
  end
  else
  begin
    a:=1;
    b:=n-a-c;
    z:=0;
    for i:=1 to n do
    begin
      if d[i]>0 then e[i]:=2
      else if d[i] = 0 then e[i]:=3
      else
      begin
        if z = 0 then
        begin
          e[i]:=1;
          z:=1;
        end
        else e[i]:=2;
      end;
    end;
  end;
  write(a,' ');
  for i:=1 to b do if e[i]=1 then write(d[i],' ');
  writeln;
  write(b,' ');
  for i:=1 to n do if e[i]=2 then write(d[i],' ');
  writeln;
  write(c,' ');
  for i:=1 to n do if e[i]=3 then write(d[i],' ');
end.