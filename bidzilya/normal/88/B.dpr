var
  i,j,k,l,n,m,x,q:integer;
  mn:real;
  s:string;
  a:array[1..30,1..30]of char;
  b:array['a'..'z']of real;
  c:char;
begin
  readln(n,m,x);
  for i:=1 to n do begin
    readln(s);
    for j:=1 to m do
      a[i,j]:=s[j];
  end;
  readln(q);
  readln(s);
  for c:='a' to 'z' do
    b[c]:=200001.0;
  for i:=1 to n do
    for j:=1 to m do begin
      if a[i,j]='S' then continue;
      mn:=200000.0;
      for k:=1 to n do
        for l:=1 to m do
          if (a[k,l]='S')and(sqrt(sqr(i-k)+sqr(j-l))<mn)then mn:=sqrt(sqr(i-k)+sqr(j-l));
      if mn<b[a[i,j]] then b[a[i,j]]:=mn;
    end;
  k:=0;
  for i:=1 to q do begin
    if (s[i]>='A')and(s[i]<='Z') then begin
      s[i]:=chr(ord(s[i])+32);
      if b[s[i]]=200000.0 then begin writeln('-1'); halt; end;
      if b[s[i]]>x then inc(k);
    end;
    if b[s[i]]=200001.0 then begin writeln('-1'); halt; end;
  end;
  writeln(k);
end.