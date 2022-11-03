var
  s,st:string;
  a:array[1..30]of string;
  b:array[1..6]of boolean;
  k,i:integer;
  bol:boolean;
  
function prov(str:string):boolean;
var i:integer;
begin
  result:=true;
  for i:=1 to k do
    if a[i]=str then begin result:=false; break; end;
end;
  
procedure getper(str:string;a,b,c:integer);
var 
    t:string;
    m:char;
begin
  if not bol then exit;
  t:=str;
  if not prov(str) then begin bol:=false; exit; end;
  if a<3 then begin
    m:=str[2];
    str[2]:=str[1];
    str[1]:=str[4];
    str[4]:=str[3];
    str[3]:=m;
    getper(str,a+1,b,c);
  end;
  str:=t;
  if b<3 then begin
    m:=str[5];
    str[5]:=str[1];
    str[1]:=str[6];
    str[6]:=str[3];
    str[3]:=m;
    getper(str,a,b+1,c);
  end;
  str:=t;
  if c<3 then begin
    m:=str[2];
    str[2]:=str[6];
    str[6]:=str[4];
    str[4]:=str[5];
    str[5]:=m;
    getper(str,a,b,c+1);
  end;
end;
  
procedure rec(n:integer);
var i:integer;
begin
  if n=7 then begin
    bol:=true;
    getper(st,0,0,0);
    if bol then begin inc(k); a[k]:=st; end;
  end
  else
  for i:=1 to 6 do
    if not b[i] then begin b[i]:=true; st[n]:=s[i]; rec(n+1); b[i]:=false; end;
end;
  
begin
  readln(s);
  k:=0;
  for i:=1 to 6 do
    b[i]:=false;
  setlength(st,7);
  rec(1);
  write(k);
end.