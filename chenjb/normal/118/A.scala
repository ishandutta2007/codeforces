object test {
	def main(args: Array[String]){
		print(readLine.toLowerCase.replaceAll("[aeiouy]","").map("."+_).mkString)
	}
}