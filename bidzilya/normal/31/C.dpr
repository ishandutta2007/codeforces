{$APPTYPE CONSOLE}
uses Math;
var n,i,j,ka,r1,r2:integer;
    l,r:array[1..5000]of integer;
    col:array[1..5000]of integer;
begin
  readln(n);
  for i:=1 to n do
    readln(l[i],r[i]);
  fillchar(col,sizeof(col),0);
  ka:=0;
  for i:=1 to n-1 do
    for j:=i+1 to n do
    begin
      r1:=max(l[i],l[j]);
      r2:=min(r[i],r[j]);
      if r1<r2 then
      begin
        inc(col[i]);
        inc(col[j]);
        inc(ka);
      end;
    end;
  if ka=0 then
  begin
    writeln(n);
    for i:=1 to n do
      write(i,' ');
  end
  else begin
    r1:=0;
    for i:=1 to n do
      if col[i]=ka then
      begin
        inc(r1);
        r[r1]:=i;
      end;
    if (r1=0)then
    begin
      write(0);
      halt;
    end;
    writeln(r1);
    for i:=1 to r1 do write(r[i],' ');
  end;
end.