program task_d2;

{$APPTYPE CONSOLE}

const md = round(1e9)+7;
      nmax = 2000;
var n,k,i,j,it,x,y,len: integer;
    used: array[1..nmax]of boolean;
    Head: array[1..nmax]of integer;
    Next,T: array[1..2*nmax*nmax]of integer;
    ans,m: int64;
    ok: boolean;

procedure dfs(v: integer);
var i: integer;
begin
  used[v]:=true;
  i:=Head[v];
  while (i<>-1)do begin
    if (not used[T[i]])then
      dfs(T[i]);
    i:=Next[i];
  end;
end;

begin
  read(n,m,k);
  len:=0;
  for i:=1 to n do Head[i]:=-1;
  for i:=1 to n-k+1 do begin
    x:=i; y:=i+k-1;
    while (x<y)do begin
      inc(len);
      Next[len]:=Head[x];
      Head[x]:=len;
      T[len]:=y;
      inc(len);
      Next[len]:=Head[y];
      Head[y]:=len;
      T[len]:=x;
      inc(x);dec(y);
    end;
  end;
  it:=0;
  for i:=1 to n do
    if (not used[i])then begin
      inc(it);
      dfs(i);
    end;
  ans:=1;
  for i:=1 to it do ans:=ans*m mod md;
  write(ans);
end.