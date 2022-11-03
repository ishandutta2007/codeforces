var
  s:string;
  a:Array[1..100]of integer;
  i:integer;
  
begin
  readln(s);
  a[1]:=1;
  for i:=2 to length(s) do begin
    if s[i]=s[i-1] then a[i]:=a[i-1]+1 else a[i]:=1;
    if a[i]>=7 then begin writeln('YES'); halt; end;
  end;
  writeln('NO');
end.