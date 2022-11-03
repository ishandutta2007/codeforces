{$APPTYPE CONSOLE}

var s:string;
    a,b:array[0..300]of integer;
    i:integer;
begin
  readln(s);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  for i:=1 to length(s) do inc(a[ord(s[i])]);
  readln(s);
  for i:=1 to length(s) do inc(a[ord(s[i])]);
  readln(s);
  for i:=1 to length(s) do inc(b[ord(s[i])]);
  for i:=0 to 300 do
    if (b[i]<>a[i])then begin write('NO'); halt; end;
  write('YES');
end.