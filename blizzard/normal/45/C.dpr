{$Apptype console}
{$O-}
uses SysUtils, Math;
type t = record nommas, l, r : longint; end;
     t1 = record x, y : longint; end;
var x1, x2, x3, kol,st, k, i, n, n1 : longint; 
    m : array [0..500000] of longint;
    tree : array [0..2000000] of t;
    s : array [-10..500000] of char;
    sl : string;
    ans : array [-1..500000] of t1;
function minim(i, j : longint) : longint;
begin
  if s[j] = 'B' then minim := maxlongint else minim := abs(m[j] - m[i]);
end;

function min1(a, b : t) : t;
begin
  if (s[a.nommas] = 'G') or (a.nommas = 0) or (a.nommas = n1 + 1) then min1 := b else
  if (s[b.nommas] = 'G') or (b.nommas = 0) or (b.nommas = n1 + 1) then min1 := a else
  BEGIN
    if min(minim(a.nommas, a.l), minim(a.nommas, a.r)) > min(minim(b.nommas, b.l), minim(b.nommas, b.r)) then min1 := b else
    if min(minim(a.nommas, a.l), minim(a.nommas, a.r)) < min(minim(b.nommas, b.l), minim(b.nommas, b.r)) then min1 := a else
    if (a.nommas < b.nommas) then min1 := a else min1 := b;
  END;
end;
procedure update(i : longint);
var nom : longint;
begin
  nom := n + i - 1;
  nom := nom div 2;
  while nom > 0 do
    begin
      tree[nom] := min1(tree[nom * 2], tree[nom * 2 + 1]);
      nom := nom div 2;
    end;
end;


begin
  {reset(input, 'input.txt');
  rewrite(output, 'output.txt'); }
  readln(n1);
  readln(sl);
  for i := 1 to length(sl) do s[i] := sl[i];
  s[0] := 'B';
  s[n1 + 1] := 'B';
  for i := 1 to n1 do read(m[i]);
  st := 1;
  while st < n1 do st := st * 2;
  n := st;
  k := n - 1;
  for i := 1 to n1 do
    begin
      inc(k);
      tree[k].l := i - 1;
      tree[k].r := i + 1;
      tree[k].nommas := i;
    end;
  for i := n - 1 downto 1 do tree[i] := min1(tree[2 * i], tree[2 * i + 1]);
  kol := 0;
  while true do
    begin
      if (((tree[1].l = 0) or (s[tree[1].l] = 'B')) and ((tree[1].r = n1 + 1) or (s[tree[1].r] = 'B'))) or
      (tree[1].nommas = 0) or (tree[1].nommas = n1 + 1) or (s[tree[1].nommas] = 'G')
       then break;
      if (minim(tree[1].nommas, tree[1].l) > minim(tree[1].nommas, tree[1].r))
      then begin
        inc(kol);
        ans[kol].x := tree[1].nommas;
        ans[kol].y := tree[1].r;
        x1 := tree[1].l;
        x2 := tree[1].nommas;
        x3 := tree[n + tree[1].r - 1].r;
        tree[n + tree[1].r - 1].l := 0;
        tree[n + tree[1].r - 1].r := n1 + 1;
        update(tree[1].r);

      end else
        begin
         inc(kol);
         ans[kol].y := tree[1].nommas;
         ans[kol].x := tree[1].l;
         x1 := tree[n + tree[1].l - 1].l;
         x2 := tree[1].nommas;
         x3 := tree[1].r;
         tree[n + tree[1].l - 1].l := 0;
         tree[n + tree[1].l - 1].r := n1 + 1;
         update(tree[1].l);

        end;
      tree[n + x1 - 1].r := x3;
      tree[n + x3 - 1].l := x1;
      tree[n + x2 - 1].l := 0;
      tree[n + x2 - 1].r := n1 + 1;
      if (n1 >= x1) and (x1 <> 0) then update(x1);
      if (n1 >= x2) and (x2 <> 0) then update(x2);
      if (n1 >= x3) and (x3 <> 0) then update(x3);

    end;
  writeln(kol);
  for i := 1 to kol do writeln(ans[i].x, ' ', ans[i].y);
end.