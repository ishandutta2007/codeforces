const NMAX = 3000;
var A,B,Q,P:array[1..2*NMAX]of integer;
    n,i,cst,cfi:integer;

procedure circle;
var i:integer;
begin
  for i:=1 to n do
    Q[i]:=-1;
  Q[cst]:=0;
  Q[cfi]:=0;
  i:=P[cfi];
  while i<>cst do
  begin
    Q[i]:=0;
    i:=P[i];
  end;
end;

procedure bfs;
var i:integer;
    bol:boolean;
begin
  bol:=true;
  while bol do
  begin
    bol:=false;
    for i:=1 to 2*n do
      if (Q[A[i]]<>-1)and(Q[B[i]]=-1)then
      begin
        bol:=true;
        Q[B[i]]:=Q[A[i]]+1;
      end;
  end;
  for i:=1 to n do
    write(Q[i],' ');
end;

procedure dfs(v:integer);
var i:integer;
begin
  Q[v]:=1;
  for i:=1 to 2*n do
    if (A[i]=v)then
      if Q[B[i]]=0 then
      begin
        P[B[i]]:=v;
        dfs(B[i]);
      end
      else
      if B[i]<>P[v]then
      begin
        cst:=B[i];
        cfi:=v;
        circle;
        bfs;
        halt;
      end;
end;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  readln(n);
  for i:=1 to n do
  begin
    readln(A[i],B[i]);
    A[n+i]:=B[i];
    B[n+i]:=A[i];
  end;
  for i:=1 to n do Q[i]:=0;
  P[1]:=-1;
  dfs(1);
end.