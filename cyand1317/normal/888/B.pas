program Buggy_Robot;

const
   maxn = 103;

var
   n: longint;
   s: string;

   x, y, i: longint;

begin
   readln(n);
   readln(s);

   x := 0; y := 0;
   for i := 1 to n do
      case s[i] of
         'L': dec(x);
         'R': inc(x);
         'U': inc(y);
         'D': dec(y);
      end;

   if x < 0 then x := -x;
   if y < 0 then y := -y;
   writeln(n - (x + y));
end.