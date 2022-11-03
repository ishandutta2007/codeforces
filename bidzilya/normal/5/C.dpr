program task_c;

{$APPTYPE CONSOLE}

uses
  SysUtils, Math;
const nmax = 1000000;
var n,i,j,len,ca,ta,ans1,ans2,tt: integer;
    s: string;
begin
//assign(input,'input.txt');reset(input);
//assign(output,'output.txt');rewrite(output);
  readln(s);
  n:=length(s);
  ta:=0;ca:=1;
  len:=0;
  tt:=0;
  for i:=1 to n do
    if (s[i]='(')then begin
      inc(len);
      inc(tt);
    end else
    if (s[i]=')')and(len>0)then begin
      dec(len);inc(tt);
      if (len=0)then begin
        if (tt = ta)then inc(ca);
        if (tt > ta)then begin
          ta:=tt;
          ca:=1;
        end;
      end;
    end else begin
      len:=0;
      tt:=0;
    end;
  ans1:=ta;ans2:=ca;
  ta:=0;ca:=1;
  len:=0;
  tt:=0;
  for i:=n downto 1 do
    if (s[i]=')')then begin
      inc(len);
      inc(tt);
    end else
    if (s[i]='(')and(len>0)then begin
      dec(len);inc(tt);
      if (len=0)then begin
        if (tt = ta)then inc(ca);
        if (tt > ta)then begin
          ta:=tt;
          ca:=1;
        end;
      end;
    end else begin
      len:=0;
      tt:=0;
    end;
  if (ta>ans1)then begin
    ans1:=ta;
    ans2:=ca;
  end;
  writeln(ans1,' ',ans2);
end.