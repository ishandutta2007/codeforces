function main() {
  var t = readline().split(' ').map(x => +x), n = t[0], k = t[1];
  var a = readline().split(' ').map(x => +x);
  a.sort((u, v) => v - u);
  var ans = 0;
  for (var i = 0; i < n; i += k) {
    ans += (a[i] - 1) * 2;
  }
  print(ans);
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
    if (typeof print == 'undefined') print = console.log;
    main();
  });
} else main();