const maxn = 101010;
var
  n, m: longint;
  a: array[0..maxn] of integer;
  head, nxt, gr: array[0..2 * maxn] of longint;
  cur: longint = 0;

procedure addedge(u, v: longint);
begin
  gr[cur] := v;
  nxt[cur] := head[u];
  head[u] := cur;
  inc(cur);
end;

procedure enter;
var i, u, v: longint;
begin
  read(n, m);
  for i := 1 to n do read(a[i]);
  fillchar(head, sizeof(head), 255);
  fillchar(nxt, sizeof(nxt), 255);
  for i := 1 to n - 1 do begin
    read(u, v);
    addedge(u, v);
    addedge(v, u);
  end;
end;

var
  cnt: array[0..maxn] of longint;
  ans: longint = 0;
procedure dfs(u, p: longint);
var
  i, v: longint;
begin
  if (a[u] = 0) then cnt[u] := 0
  else cnt[u] := cnt[p] + 1;
  if (cnt[u] > m) then exit();
  if (u <> 1) and (nxt[head[u]] = -1) then begin
    inc(ans);
    //writeln(stderr, u);
  end;

  i := head[u];
  while i <> -1 do begin
    v := gr[i];
    if v <> p then dfs(v, u);
    i := nxt[i];
  end;
end;

begin
  enter;
  fillchar(cnt, sizeof(cnt), 0);
  dfs(1, 1);
  writeln(ans);
end.