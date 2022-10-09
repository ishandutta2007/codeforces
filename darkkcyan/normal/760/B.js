function main() {
  var n = +nxt(), m = +nxt(), k = +nxt() - 1;
  function ok(val) {
    var u = Math.min(k + val - 1, n - 1) - k + 1;
    var v = k - Math.max(k - val + 1, 0) + 1;
    var s1 = (val + val - u + 1) * u / 2;
    var s2 = (val + val - v + 1) * v / 2;
    return (s1 + s2 - val + n - u - v + 1) <= m;
  }
  var l = 1, r = m;
  while (l < r) {
    var mid = l + ((r - l + 1) >> 1);
    if (ok(mid)) l = mid;
    else r = mid - 1;
  }
  print(l);
}

var line = null, linepos = 0;
function nxt() {
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