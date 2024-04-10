program Task1;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

var s,s1,s2,s3: string;
    i,j,k,sum,st: integer;

function may(s: string): boolean;
var t: integer;
begin
  if (s[1]='0')then begin
    if (length(s)=1)then
      may:=true
    else
      may:=false;
    exit;
  end;
  if (length(s)>7)then begin
    may:=false;
    exit;
  end;
  t:=strtoint(s);
  if (t>1000000)then begin
    may:=false;
    exit;
  end;
  st:=st+t;
  may:=true;
end;

begin
  read(s);
  sum:=-1;
  for i:=1 to length(s)-2 do
    for j:=i+1 to length(s)-1 do begin
      s1:=copy(s,1,i);
      s2:=copy(s,i+1,j-i);
      s3:=copy(s,j+1,length(s)-j);
      st:=0;
      if (may(s1)and
          may(s2)and
          may(s3))then
            sum:=max(sum,st);
    end;
  write(sum);
end.