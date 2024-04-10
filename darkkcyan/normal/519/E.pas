Program Main;

const maxn = 101010;
const maxlg = 20;
var
  n, m: longint;
  
var
  val, next, head: array[0..maxn * 2] of longint;
  cur: longint;
procedure addedge(u, v: longint);
begin
  val[cur] := v;
  next[cur] := head[u];
  head[u] := cur;
  inc(cur);
end;

procedure preenter;
var
  i, u,v : longint;
begin
  read(n);
  cur := 0;
  fillchar(head, sizeof(head), 255);
  for i := 1 to n - 1 do begin
    read(u, v);
    addedge(u, v);
    addedge(v, u);
  end;
end;

var
  cnt, d: array[0..maxn] of longint;
  up: array[0..maxlg, 0..maxn] of longint;
  
procedure dfs(u: longint);
var
  i, v: longint;
begin
  for i := 1 to maxlg do up[i][u] := up[i - 1][up[i - 1][u]];
  i := head[u];
  cnt[u] := 1;
  while i <> -1 do begin
    v := val[i]; i := next[i];
    if v = up[0][u] then continue;
    up[0][v] := u;
    d[v] := d[u] + 1;
    dfs(v);
    inc(cnt[u], cnt[v]);
  end;
end;

function lift(u, d: longint): longint;
var i: longint;
begin
  for i := 0 to maxlg do begin
    if d = 0 then break;
    if d mod 2 = 1 then u := up[i][u];
    d := d div 2;
  end;
  exit(u);
end;

function lca(u, v: longint): longint;
var i, t: longint;
begin
  if d[u] < d[v] then begin
    t := u; u := v; v := t;
  end;
  // write(stderr, u, ' ');
  u := lift(u, d[u] - d[v]);
  // writeln(stderr, u);
  if u = v then exit(u);
  for i := maxlg downto 0 do begin
    if up[i][u] <> up[i][v] then begin
      u := up[i][u];
      v := up[i][v];
    end;
  end;
  exit(up[0][u]);
end;

function solve(u, v: longint): longint;
var
  l, dis, c1, c2: longint;
begin
  if u = v then exit(n);
  l := lca(u, v);
  dis := d[u] + d[v] - 2 * d[l];
  // writeln(stderr, u, ' ', v, ' ', l, ' ', dis);
  if (dis mod 2 = 1) then exit(0);
  if (d[u] = d[v]) then begin
    u := lift(u, dis div 2 - 1);
    v := lift(v, dis div 2 - 1);
    exit(n - cnt[u] - cnt[v]);
  end;
  if d[u] < d[v] then u := v;
  u := lift(u, dis div 2 - 1);
  c1 := cnt[u];
  c2 := n - cnt[up[0][u]];
  exit(n - c1 - c2);
end;

var u, v: longint;
begin
  preenter;
  d[1] := 0;
  up[0][1] := 1;
  dfs(1);
  read(m);
  while m > 0 do begin
    dec(m);
    read(u,v);
    writeln(solve(u, v));
  end;
end.