program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils,Math;
const nmax = 111111;
var n,m,i,j,k,ans: integer;
    Head: array[1..nmax]of integer;
    Next: array[1..2*nmax]of integer;

procedure calc(v: integer);
var y1,y2,l,cnt: integer;
begin
  y1:=Head[v];y2:=Head[v];cnt:=1;
  while (y1<>-1)do begin
    while (Next[y2]<>-1)do begin
      l:=y1-Next[y2]+1;
      if (l-cnt-1<=k)then begin
        y2:=Next[y2];
        inc(cnt);
      end else
        break;
    end;
    ans:=max(ans,cnt);
    y1:=Next[y1];
    dec(cnt);
  end;
end;

begin
  read(n,m,k);
  for i:=1 to m do HEad[i]:=-1;
  for i:=1 to n do begin
    read(j);
    Next[i]:=Head[j];
    Head[j]:=i;
  end;
  ans:=0;
  for i:=1 to m do calc(i);
  write(ans);
end.