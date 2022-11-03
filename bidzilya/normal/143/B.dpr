program B;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var s,ans:string;
    i,p,predel:integer;
    sign:boolean;
begin
  readln(s);
  ans:='.';
  p:=pos('.',s);
  if (p=0)then ans:=ans+'00' else
    if (p=length(s)-1)then ans:=ans+s[p+1]+'0' else
      ans:=ans+s[p+1]+s[p+2];
  if (p=0)then i:=length(s)else i:=p-1;
  if (s[1]='-')then begin
    sign:=true;
    predel:=2;
  end else begin
    sign:=false;
    predel:=1;
  end;
  p:=0;
  while (i>=predel)do begin
    ans:=s[i]+ans;
    inc(p);
    if (p=3)then begin
      p:=0;
      if (i<>predel)then ans:=','+ans;
    end;
    dec(i);
  end;
  ans:='$'+ans;
  if (sign)then ans:='('+ans+')';
  writeln(ans);
end.