program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

const max = 300000;
var
  n,m,k,i,u,v,ll,ff,min:integer;
  f,s,c,l:array[1..max] of integer;
  sk:array[1..max] of boolean;
begin
  {assign(input,'in.txt');
  reset(input);  }
  readln(n,m,k);
  ff:=0;
  for i:=1 to max do
  begin
    f[i]:=0;
    s[i]:=-1;
    c[i]:=-1;
    l[i]:=0;
    sk[i]:=false;
  end;
  for i:=1 to m do
  begin
    readln(u,v,ll);
    inc(ff);
    f[ff]:=v;
    s[ff]:=c[u];
    l[ff]:=ll;
    c[u]:=ff;
    inc(ff);
    f[ff]:=u;
    s[ff]:=c[v];
    l[ff]:=ll;
    c[v]:=ff;
  end;
  for i:=1 to k do
  begin
    read(u);
    sk[u]:=true;
  end;
  min:=2000000000;
  for i:=1 to n do
  begin
    if sk[i]=true then
    begin
      v:=c[i];
      while v>-1 do
      begin
        if (sk[f[v]]=false) and (l[v]<min) then
          min:=l[v];
        v:=s[v];
      end;
    end;
  end;
  if min=2000000000 then min:=-1;
  writeln(min);
 // close(input);
end.