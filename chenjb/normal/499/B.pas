var
  a,b,c:array[1..4001]of string;
  s:string;
  n,m,t,i,j:longint;
function readstr:string;
var
  c:char;
  s:string;
begin
  s:='';
  read(c);
  while not (c in['a'..'z']) do read(c);
  while c in ['a'..'z']do
  begin
    s:=s+c;
    read(c);
  end;
  exit(s);
end;
begin

  readln(n,m);
  for i:=1 to m do
  begin
    a[i]:=readstr;
    b[i]:=readstr;
    if length(a[i])>length(b[i]) then c[i]:=b[i] else c[i]:=a[i];
    readln;
  end;
  for i:=1 to n do
  begin
    s:=readstr;
    for j:=1 to m do
      if s=a[j] then
      begin
        t:=j;
        break;
      end;
    if i<>1 then write(' ');
    write(c[t]);
  end;
  writeln;

end.