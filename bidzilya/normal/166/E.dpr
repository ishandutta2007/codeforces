program Task5;
{$apptype console}

uses SysUtils;
type integer = longint;
const md = round(1e9)+7;
var
  nkv,nkb,kv,kb,n,i: integer;

begin
  kv:=1;
  kb:=0;
  read(n);
  for i:=1 to n do begin
    nkv:=((kb+kb)mod md + kb)mod md;
    nkb:=((kb+kb)mod md + kv)mod md;
    kv:=nkv;
    kb:=nkb;
  end;
  writeln(kv);
end.