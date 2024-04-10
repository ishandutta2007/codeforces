function main() {
  var n = +next();
  var s = next();
  var t = {0: -1};
  var sum = 0;
  var ans = 0;
  for (var i = -1; ++ i < n; ) {
    sum += s[i] === '1' ? 1 : -1;
    if (t[sum] != null) {
      ans = Math.max(ans, i - t[sum]);
    } else t[sum] = i;
  }
  print(ans);
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