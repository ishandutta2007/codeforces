program tmp_3;

{$APPTYPE CONSOLE}

var s1,s2:string;
    a,b:array['a'..'z']of integer;
    k,i,ans:integer;
    c:char;

function check:boolean;
var c:char;
    d:integer;
begin
  d:=0;
  for c:='a' to 'z' do
    if (b[c]>a[c])then d:=d+b[c]-a[c];
  if (d>k)then check:=false
  else check:=true;
end;

begin
  readln(s1);
  readln(s2);
  if (length(s2)>length(s1))then begin
    write(0);
    halt;
  end;
  for c:='a' to 'z' do begin
    a[c]:=0;
    b[c]:=0;
  end;
  k:=0;
  for i:=1 to length(s2)do
    inc(b[s2[i]]);
  for i:=1 to length(s2)do
    if (s1[i]='?')then inc(k)else
      inc(a[s1[i]]);
  ans:=0;
  for i:=1 to length(s1)-length(s2)+1 do begin
    if (check)then inc(ans);
    if (s1[i]='?')then dec(k)else
      dec(a[s1[i]]);
    if (i+length(s2)<=length(s1))then begin
      if (s1[i+length(s2)]='?')then inc(k)else
        inc(a[s1[i+length(s2)]]);
    end;
  end;
  write(ans);
end.