program Xor_MST;

const
   maxn = 200004;
   logn = 30;
   maxsz = maxn * (logn + 1);

var
   n: longint;
   a: array [1 .. maxn] of longint;

   i, u: longint;
   ans: int64;

   sz: longint;
   ch: array [1 .. maxsz, 0 .. 1] of longint;
   cnt: array [1 .. maxsz] of longint;

function min(a, b: longint): longint; begin if a < b then min := a else min := b end;

function trie_newnode(): longint;
begin
   inc(sz);
   ch[sz, 0] := -1;
   ch[sz, 1] := -1;
   cnt[sz] := 0;
   trie_newnode := sz;
end;

procedure trie_insert(x: longint);
var
   i, u, b: longint;
begin
   u := 1;
   for i := logn - 1 downto 0 do begin
      b := (x shr i) and 1;
      if ch[u, b] = -1 then ch[u, b] := trie_newnode();
      u := ch[u, b];
      inc(cnt[u]);
   end;
end;

{
   Returns the minimum xor of values x and y
   such that x is in u's subtree and y is in v's subtree
}
function trie_search(u, v: longint; dep: longint): longint;
var
   ret: longint;
begin
   if (u = -1) or (v = -1) or (cnt[u] = 0) or (cnt[v] = 0) then exit(maxlongint);
   if dep = -1 then exit(0);
   ret := maxlongint;
   ret := min(ret, trie_search(ch[u, 0], ch[v, 0], dep - 1));
   ret := min(ret, trie_search(ch[u, 1], ch[v, 1], dep - 1));
   if ret = maxlongint then begin
      ret := min(ret, trie_search(ch[u, 0], ch[v, 1], dep - 1) or (1 shl dep));
      ret := min(ret, trie_search(ch[u, 1], ch[v, 0], dep - 1) or (1 shl dep));
   end;
   exit(ret);
end;

procedure trie_dfs(u: longint; dep: longint);
begin
   if ch[u, 0] <> -1 then trie_dfs(ch[u, 0], dep - 1);
   if ch[u, 1] <> -1 then trie_dfs(ch[u, 1], dep - 1);
   if (ch[u, 0] <> -1) and (cnt[ch[u, 0]] > 0)
      and (ch[u, 1] <> -1) and (cnt[ch[u, 1]] > 0)
   then begin
      inc(ans, trie_search(ch[u, 0], ch[u, 1], dep - 1) or (1 shl dep));
   end;
end;

begin
   readln(n);
   for i := 1 to n do read(a[i]);

   sz := 0;
   trie_newnode();
   for i := 1 to n do trie_insert(a[i]);

   ans := 0;
   trie_dfs(1, logn - 1);

   writeln(ans);
end.