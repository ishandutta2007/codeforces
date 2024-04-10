program K_Dominant_Character;

const
   maxn = 100005;
   alpha = 26;

var
   s: ansistring;

   ans: longint;
   i, c: longint;
   last, let: array [1 .. alpha] of longint;

function min(a, b: longint): longint; begin if a < b then min := a else min := b; end;
function max(a, b: longint): longint; begin if a > b then max := a else max := b; end;

begin
   readln(s);

   for i := 1 to alpha do begin
      let[i] := 0;
      last[i] := 0;
   end;
   for i := 1 to length(s) do begin
      c := ord(s[i]) - 96;
      let[c] := max(let[c], i - last[c]);
      last[c] := i;
   end;
   for i := 1 to alpha do let[i] := max(let[i], length(s) + 1 - last[i]);

   ans := maxlongint;
   for i := 1 to alpha do ans := min(ans, let[i]);
   writeln(ans);
end.