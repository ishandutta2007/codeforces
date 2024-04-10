{$APPTYPE CONSOLE}

var n,m,i,j:integer;
    str,stl:array[1..100,'a'..'z']of integer;
    a:array[1..100,1..100]of char;
    c:char;
begin
  readln(n,m);
  for i:=1 to 100 do
  for c:='a' to 'z' do begin str[i,c]:=0; stl[i,c]:=0; end;
  for i:=1 to n do
  begin
    for j:=1 to m do
    begin
      read(a[i,j]);
      inc(str[i,a[i,j]]);
      inc(stl[j,a[i,j]]);
    end;
    readln;
  end;
  for i:=1 to n do
    for j:=1 to m do
      if not((stl[j,a[i,j]]>1)or(str[i,a[i,j]]>1))then write(a[i,j]);
end.