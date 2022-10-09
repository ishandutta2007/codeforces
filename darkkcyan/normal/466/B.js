function main() {
  var n = +next(), a = [+next(), +next()];
  var t = 0;
  if (a[0] > a[1]) t = 1;
  var ans = [Infinity, Infinity];
  for (var i = 1; i * i <= 6 * n; ++i) {
    var f = Math.ceil(6 * n / i);
    // console.error(i, f);
    var u = Math.max(a[t], i), v = Math.max(a[t ^ 1], f);
    if (u * v < 6 * n) continue;
    if (ans[0] * ans[1] > u * v) {
      ans[t] = u;
      ans[t ^ 1] = v;
    }
  }
  print(ans[0] * ans[1]);
  print(ans[0] + " " + ans[1]);
}

var line = null, linepos = 0;
function next() {
  if (!line || linepos === line.length) {
    line = readline().split(' ');
    linepos = 0;
  }
  return line[linepos++];
}

if (typeof readline == 'undefined') {
  process.stdin.resume();
  process.stdin.setEncoding('ascii');
  
  var input_stdin = "";
  process.stdin.on('data', function (data) { input_stdin += data; });
  process.stdin.on('end', function () {
    // input_stdin = input_stdin.split(/\s/);
    input_stdin = input_stdin.split('\n');
    var curline = 0;
    readline = () => input_stdin[curline++];
    if (typeof print === 'undefined') print = console.log;
    main();
  });
} else main();