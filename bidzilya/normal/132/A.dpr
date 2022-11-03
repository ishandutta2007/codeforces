program task_c;

{$APPTYPE CONSOLE}
const st: array[1..8]of integer = (128,64,32,16,8,4,2,1);
var text,s,t: string;
    n,i,ss,tt,ans: integer;

function zerkalo(s: string): string;
var tmp: string;
    i: integer;
begin
  tmp:='';
  for i:=length(s)downto 1 do tmp:=tmp+s[i];
  zerkalo:=tmp;
end;
function fromintto2(x: integer): string;
var tmp: string;
    i: integer;
begin
  tmp:='';
  for i:=1 to 8 do
    if (x>=st[i])then begin
      tmp:=tmp+'1';
      dec(x,st[i]);
    end else
      tmp:=tmp+'0';
  fromintto2:=tmp;
end;
function from2toint(s: string): integer;
var i,x: integer;
begin
  x:=0;
  for i:=1 to length(s)do
    x:=x*2+ord(s[i])-ord('0');
  from2toint:=x;
end;
begin
  readln(text);
  text:=chr(0)+text;
  n:=length(text);
  for i:=2 to n do begin
    s:=zerkalo(fromintto2(ord(text[i])));
    t:=zerkalo(fromintto2(ord(text[i-1])));
    ss:=from2toint(s);
    tt:=from2toint(t);
    ans:=tt-ss;
    if (ans<0)then ans:=ans+256;
    writeln(ans);
  end;
end.