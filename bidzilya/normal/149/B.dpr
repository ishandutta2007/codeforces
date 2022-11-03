program task_2;
{$APPTYPE CONSOLE}

var ta,i: integer;
    a: array[1..100]of integer;
    s1,s2: array[0..5]of integer;
    ss,s: string;
function check(x: integer): boolean;
var i,h,t,st: integer;
begin
  h:=0;t:=0;
  st:=1;
  for i:=s1[0] downto 1 do begin
    if (s1[i]>=x)then begin
      check:=false;
      exit;
    end;
    h:=h+s1[i]*st;
    st:=st*x;
  end;
  st:=1;
  for i:=s2[0] downto 1 do begin
    if (s2[i]>=x)then begin
      check:=false;
      exit;
    end;
    t:=t+s2[i]*st;
    st:=st*x;
  end;
  if (t<0)or(h<0)or(t>=60)or(h>=24)then begin
    check:=false;
    exit;
  end;
  check:=true;
end;

begin
  ta:=0;
  readln(s);
  ss:=copy(s,1,pos(':',s)-1);
  s1[0]:=length(ss);
  for i:=length(ss)downto 1 do
    if (ss[i]>='A')and(ss[i]<='Z')then s1[i]:=ord(ss[i])-ord('A')+10
                                  else s1[i]:=ord(ss[i])-ord('0');
  delete(s,1,pos(':',s));
  s2[0]:=length(s);
  for i:=length(s)downto 1 do
    if (s[i]>='A')and(s[i]<='Z')then s2[i]:=ord(s[i])-ord('A')+10
                                else s2[i]:=ord(s[i])-ord('0');
  for i:=2 to 200 do
    if (check(i))then begin
      inc(ta);
      a[ta]:=i;
    end;
  if (ta=0)then write(0)else
  if (ta>100)then write(-1)else
  for i:=1 to ta do write(a[i],' ');
end.