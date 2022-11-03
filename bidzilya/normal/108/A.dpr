var
  s:string;
  a:array[1..4]of byte;
  i:integer;
  
procedure increment;
var i:integer;
begin
  inc(a[4]);
  if a[4]=10 then begin
    a[4]:=0;
    inc(a[3]);
    if a[3]=6 then begin
      a[3]:=0;
      inc(a[2]);
      if (a[1]=2)and(a[2]=4)then begin
        a[1]:=0;
        a[2]:=0;
      end else if a[2]=10 then begin
        a[2]:=0;
        inc(a[1]);
      end;
    end;
  end;
  for i:=1 to 4 do
    s[i]:=chr(a[i]+48);
end;

function pol:boolean;
var i:integer;
begin
  result:=true;
  for i:=1 to 4 do
    if s[i]<>s[5-i] then begin result:=false; break; end;
end;

begin
  readln(s);
  delete(s,3,1);
  for i:=1 to 4 do
    a[i]:=ord(s[i])-48;
  repeat
    increment;
  until pol;
  write(s[1],s[2],':',s[3],s[4]);
end.